/*
 * TI Voxel Lib component.
 *
 * Copyright (c) 2014 Texas Instruments Inc.
 */

#ifndef VOXEL_TI_TOFCAMERA_H
#define VOXEL_TI_TOFCAMERA_H

#include <DepthCamera.h>
#include <RegisterProgrammer.h>
#include <Streamer.h>

namespace Voxel
{
  
namespace TI
{

class ToFCamera: public DepthCamera
{
protected:
  Ptr<RegisterProgrammer> _programmer;
  Ptr<Streamer> _streamer;
  
  RawDataFramePtr _rawDataFrame; // Used by _captureDepthFrame(). This is not exposed to DepthCamera
  virtual bool _captureRawUnprocessedFrame(RawFramePtr &rawFrame);
  virtual bool _convertToDepthFrame(const RawFramePtr &rawFrame, DepthFramePtr &depthFrame);
  
  virtual bool _start();
  virtual bool _stop();
  
  virtual bool _initStartParams() = 0;
  
  virtual bool _getAmplitudeNormalizingFactor(float &factor) = 0;
  virtual bool _getDepthScalingFactor(float &factor) = 0;
  
public:
  ToFCamera(const String &name, DevicePtr device): DepthCamera(name, device) {}
  
  virtual bool isInitialized() const
  {
    return _programmer and _programmer->isInitialized() and 
            _streamer and _streamer->isInitialized();
  }
  
  virtual ~ToFCamera() {}
};

}
}

#endif // TOFCAMERA_H
