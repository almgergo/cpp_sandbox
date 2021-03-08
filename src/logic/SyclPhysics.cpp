//
// Created by almge on 3/8/2021.
//

#include "SyclPhysics.h"

class vector_addition;

using namespace cl::sycl;

void SyclPhysics::syclHelloWorld() {
    int n = 20;
    cl::sycl::float4 a = {1.0, 2.0, 3.0, 4.0};
    cl::sycl::float4 b = {4.0, 3.0, 2.0, 1.0};
    cl::sycl::float4 c = {0.0, 0.0, 0.0, 0.0};
    try {
        cl::sycl::default_selector device_selector;

        cl::sycl::queue queue(device_selector);
        std::cout << "Running on "
                  << queue.get_device().get_info<cl::sycl::info::device::name>()
                  << "\n";
        {
            cl::sycl::buffer<cl::sycl::float4, 1> a_sycl(&a, cl::sycl::range<1>(1));
            cl::sycl::buffer<cl::sycl::float4, 1> b_sycl(&b, cl::sycl::range<1>(1));
            cl::sycl::buffer<cl::sycl::float4, 1> c_sycl(&c, cl::sycl::range<1>(1));

            queue.submit([&](cl::sycl::handler &cgh) {
                auto a_acc = a_sycl.get_access<cl::sycl::access::mode::read>(cgh);
                auto b_acc = b_sycl.get_access<cl::sycl::access::mode::read>(cgh);
                auto c_acc = c_sycl.get_access<cl::sycl::access::mode::discard_write>(cgh);

                cgh.single_task<class vector_addition>([=]() {
                    c_acc[0] = a_acc[0] + b_acc[0];
                });
            });
        }
        std::cout << "  A { " << a.x() << ", " << a.y() << ", " << a.z() << ", " << a.w() << " }\n"
                  << "+ B { " << b.x() << ", " << b.y() << ", " << b.z() << ", " << b.w() << " }\n"
                  << "------------------\n"
                  << "= C { " << c.x() << ", " << c.y() << ", " << c.z() << ", " << c.w() << " }"
                  << std::endl;

    } catch (cl::sycl::exception const &e) {
        std::cout << "SYCL exception caught: " << e.what() << '\n';
        std::cout << "SYCL exception caught: " << e.get_cl_code() << '\n';
    }
}

//void SyclPhysics::InteractParticles(Particle &particle1, Particle &particle2) {
//    size_t n = 10;
//    cl::sycl::queue deviceQueue;
//    cl::sycl::range<1> numOfItems{n};
//    cl::sycl::buffer<cl::sycl::float3, 1> bufferA(VA.data(), numOfItems);
//    cl::sycl::buffer<cl::sycl::float3, 1> bufferB(VB.data(), numOfItems);
//    cl::sycl::buffer<cl::sycl::float3, 1> bufferC(VC.data(), numOfItems);
//
//    deviceQueue.submit([&](cl::sycl::handler &cgh) {
//        auto accessorA = bufferA.template get_access<sycl_read>(cgh);
//        auto accessorB = bufferB.template get_access<sycl_read>(cgh);
//        auto accessorC = bufferC.template get_access<sycl_write>(cgh);
//
//        auto kern = [=](cl::sycl::id<1> wiID) {
//            accessorC[wiID] = accessorA[wiID] + accessorB[wiID];
//        };
//        cgh.parallel_for<class SimpleVadd<T>>(numOfItems, kern);
//    });
//}
constexpr cl::sycl::access::mode sycl_read = cl::sycl::access::mode::read;
constexpr cl::sycl::access::mode sycl_write = cl::sycl::access::mode::write;
class GravitateParticles;

void SyclPhysics::interactParticles(std::vector<std::unique_ptr<Particle>> &particles) {

    vec<float, 4> particleCoordinates(particles.size());

    auto mapped = std::transform(particles.begin(), particles.end(), particleCoordinates.begin(),
                                 [](std::unique_ptr<Particle> &p) -> float4 {
                                     return float4{p->position[0], p->position[1], p->position[2], 0.0f};
                                 });

//    std::cout << "  A { " << particleCoordinates[0].x() << ", " << particleCoordinates[0].y() << ", " << particleCoordinates[0].z() << " }\n"
//              << "+ B { " << particles[0]->position[0] << ", " << particles[0]->position[1] << ", " << particles[0]->position[2] << " }\n"
//              << std::endl;

    std::cout << "particles: " << particles.size() << ", mappedCooridnates: " << particleCoordinates.size()
              << std::endl;

    size_t n = 10;
    cl::sycl::queue deviceQueue;
    cl::sycl::range<1> numOfItems{particleCoordinates.size()};
    cl::sycl::buffer<std::vector<float4>, 1> buffer(&particleCoordinates, numOfItems);

    deviceQueue.submit([&](cl::sycl::handler &cgh) {
        auto accessorA = buffer.template get_access<sycl_write>(cgh);

        auto kern = [=](cl::sycl::id<1> wiID) {
            accessorA[wiID][0] = accessorA[wiID][0] + 0.1f;
        };
        cgh.parallel_for<class GravitateParticles>(numOfItems, kern);
    });
}
