#include "usbmanager.h"

USBManager::USBManager()
{
    int res = libusb_init(&cTx);
    if(res < 0)
    {
        qDebug() << "Failed to initialize libusb: " << libusb_error_name(res);
        cTx = nullptr;
    }
}

USBManager::~USBManager()
{
    if(dev_handle)
    {
        libusb_close(dev_handle);
    }
    if(cTx)
    {
        libusb_exit(cTx);
    }
}

bool USBManager::openDevice(uint16_t vid, uint16_t pid)
{
    dev_handle = libusb_open_device_with_vid_pid(cTx, vid, pid);
    if(dev_handle == nullptr)
    {
        qDebug() << "Cannot open device with VID: " << vid << " PID: " << pid;
        return false;
    }
    qDebug() << "Device opened successfully.";
    return true;
}

bool USBManager::readData(unsigned char *data, int length)
{
    int actual_length;
    int res = libusb_bulk_transfer(dev_handle, (1 | LIBUSB_ENDPOINT_IN), data, length, &actual_length, 0);
    if(res == 0 && actual_length > 0)
    {
        qDebug() << "Data read: " << data;
        return true;
    }
    else
    {
        qDebug() << "Failed to read data: " << libusb_error_name(res);
        return false;
    }
}

bool USBManager::writeData(unsigned char *data, int length)
{
    int actual_length;
    int res = libusb_bulk_transfer(dev_handle, (1 | LIBUSB_ENDPOINT_OUT), data, length, &actual_length, 0);
    if(res == 0)
    {
        qDebug() << "Data writen successfully.";
        return true;
    }
    else
    {
        qDebug() << "Failed to read data: " << libusb_error_name(res);
        return false;
    }
}

void USBManager::disconnectDevice()
{
    if(dev_handle)
    {
        libusb_close(dev_handle);
        dev_handle = nullptr;
        qDebug() << "Device disconnected";
    }
    else
    {
        qDebug() << "No device to disconnected";
    }
}
