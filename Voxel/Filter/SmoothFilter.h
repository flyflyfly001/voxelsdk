/*
 * TI Voxel Lib component.
 *
 * Copyright (c) 2014 Texas Instruments Inc.
 */

#ifndef VOXEL_SMOOTH_H
#define VOXEL_SMOOTH_H

#include "Filter.h"

#define _MATH_DEFINES
#include <math.h>

namespace Voxel
{
  
/**
 * \addtogroup Flt
 * @{
 */

class SmoothFilter: public Filter 
{
protected:
  float _sigma;
  
  FrameSize _size;
  
  float _fastGaussian(float x2);
  
  virtual void _onSet(const FilterParameterPtr &f);
  
  template <typename T>
  bool _filter(const T *in, T *out);
  
  virtual bool _filter(const FramePtr &in, FramePtr &out);
  
public:
  SmoothFilter(float sigma = 0.5);
  virtual ~SmoothFilter() {}
  
  virtual void reset();
};


/**
 * @}
 */

}
#endif // VOXEL_SMOOTH_H
