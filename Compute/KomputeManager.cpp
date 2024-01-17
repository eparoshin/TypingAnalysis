#include "KomputeManager.h"



namespace NSApplication {
namespace NSCompute {
namespace NSKomputeManagerDetail {

CVulkanDevices::CVulkanDevices() {
  initializeDevicesInfo();
}



int CVulkanDevices::getDevicesCount() {
  const static int device_count = 
  cudaError_t result = cudaGetDeviceCount(&device_count);
  if (result != cudaSuccess)
    throw std::runtime_error("");
  return device_count;
}

}
}
}
