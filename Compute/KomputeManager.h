#ifndef NSAPPLICATION_NSCOMPUTE_KOMPUTEMANAGER_H
#define NSAPPLICATION_NSCOMPUTE_KOMPUTEMANAGER_H

#include <vector>

#include <memory>

#include <vulkan/vulkan.h>

namespace NSApplication {
namespace NSCompute {

namespace NSKomputeManagerDetail {

class CVulkanDevices {
  struct CVulkanDeviceInfo {
    uint32_t ApiVersion = 0;
    uint32_t DriverVersion = 0;
    VkPhysicalDeviceType DeviceType = VK_PHYSICAL_DEVICE_TYPE_OTHER;
  };

  using CVulkanDevicesContainer = std::vector<CVulkanDeviceInfo>;

public:
  CVulkanDevices();

protected:
  static int getDevicesCount();
  CVulkanDeviceInfo getVulkanDeviceInfo(int devID);
  void initializeDevicesInfo();

  CVulkanDevicesContainer Devices_;

};
}

class CKomputeManager {
public:
  CKomputeManager();

private:
  class CKomputeManagerImpl;

  std::unique_ptr<CKomputeManagerImpl> Impl;

};
}
}

#endif// NSAPPLICATION_NSCOMPUTE_KOMPUTEMANAGER_H
