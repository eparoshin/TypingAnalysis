#ifndef NSAPPLICATION_NSCOMPUTE_SHADEROPS_H
#define NSAPPLICATION_NSCOMPUTE_SHADEROPS_H

 
#include <kompute/Algorithm.hpp>
#include <kompute/Tensor.hpp>
#include <kompute/operations/OpAlgoDispatch.hpp>

#include "Shader/shaderMaxvellBoltzmannDerivative0.hpp"
#include "Shader/shaderMaxvellBoltzmannDerivative1.hpp"
#include "Shader/shaderNormalDerivative0.hpp"
#include "Shader/shaderNormalDerivative1.hpp"
#include "Shader/shaderNormalDerivative2.hpp"
#include "Shader/shaderRayleighDerivative0.hpp"
#include "Shader/shaderRayleighDerivative1.hpp"

#include <vector>
#include <memory>

namespace NSApplication {
namespace NSCompute {

using kp::Tensor;
using kp::OpAlgoDispatch;
using kp::Algorithm;


template<int64_t derivative>
class OpNormal : public OpAlgoDispatch {
private:
  static std::vector<uint32_t> chooseNormalSpirv();

public:
  OpNormal(std::vector<std::shared_ptr<Tensor>> tensors, std::shared_ptr<Algorithm> algorithm) {
    if (tensors.size() != 3) {
             throw std::runtime_error("Kompute OpMult expected 3 tensors but got " + tensors.size());
    }

    const static std::vector<uint32_t> spirv = chooseNormalSpirv();

    algorithm->rebuild<>(tensors, spirv);
  }
};

template<>
inline std::vector<uint32_t> OpNormal<0>::chooseNormalSpirv() {
  return {};
}

template<>
inline std::vector<uint32_t> OpNormal<1>::chooseNormalSpirv() {
  return {};
}

template<>
inline std::vector<uint32_t> OpNormal<2>::chooseNormalSpirv() {
  return {};
}

}
}

#endif // NSAPPLICATION_NSCOMPUTE_SHADEROPS_H
