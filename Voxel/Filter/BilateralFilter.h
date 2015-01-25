/*
 * TI Voxel Lib component.
 *
 * Copyright (c) 2014 Texas Instruments Inc.
 */

#ifndef VOXEL_BILATERAL_H
#define VOXEL_BILATERAL_H

#include "Filter.h"

#define _MATH_DEFINES
#include <math.h>

namespace Voxel
{
  
/**
 * \addtogroup Flt
 * @{
 */

class BilateralFilter: public Filter
{
protected:
  float _sigma;
  
  FrameSize _size;
  
  float _fastGaussian(float x2);
  
  virtual void _onSet(const FilterParameterPtr &f);
  
  template <typename T, typename T2>
  bool _filter(const T *in, const T2 *ref, T *out);
  
  virtual bool _filter(const FramePtr &in, FramePtr &out);
  
public:
  BilateralFilter(float sigma = 0.5);
  virtual ~BilateralFilter() {}
  
  virtual void reset();
};

/**
 * @}
 */

}

#endif // VOXEL_BILATERAL_H