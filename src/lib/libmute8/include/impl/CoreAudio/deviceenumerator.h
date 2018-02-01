#ifndef COREDEVICEENUMERATOR_H
#define COREDEVICEENUMERATOR_H

#include <ideviceenumerator.h>

namespace mute8
{

class CoreDeviceEnumerator : public IDeviceEnumerator
{
public:

    CoreDeviceEnumerator();
    virtual ~CoreDeviceEnumerator();

    virtual bool populate();
    virtual void clear();
    virtual size_t count() const;

    using IDeviceEnumerator::devices; // also use overloaded interface methods
    virtual DeviceList devices(boost::optional<IAudioDevice::Type> type, boost::optional<IAudioDevice::State> state) const;
    virtual std::shared_ptr<IAudioDevice> defaultDevice(boost::optional<IAudioDevice::Type> type) const;

private:

    DeviceList _devices;

    bool comInit;
};

}

#endif // COREDEVICEENUMERATOR_H
