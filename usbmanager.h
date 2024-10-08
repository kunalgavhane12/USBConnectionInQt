#ifndef USBMANAGER_H
#define USBMANAGER_H

#include <libusb-1.0/libusb.h>
#include <QDebug>

class USBManager
{
public:
    USBManager();
    ~USBManager();
    bool openDevice(uint16_t vid, uint16_t pid);
    bool readData(unsigned char* data, int length);
    bool writeData(unsigned char* data, int length);
    void disconnectDevice();

private:
    libusb_context *cTx = nullptr;
    libusb_device_handle *dev_handle = nullptr;
};

#endif // USBMANAGER_H
