/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_measure.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  1.0.0
 *   \brief    Interface of AiTheta Index Measure
 */

#ifndef __AITHETA2_INDEX_MEASURE_H__
#define __AITHETA2_INDEX_MEASURE_H__

#include "index_meta.h"
#include "index_module.h"

namespace aitheta2 {

/*! Index Measure
 */
struct IndexMeasure : public IndexModule
{
    //! Index Measure Pointer
    typedef std::shared_ptr<IndexMeasure> Pointer;

    //! Matrix Distance Function
    typedef void (*MatrixDistanceHandle)(const void *m, const void *q,
                                         size_t dim, float *out);

    //! Matrix Distance Function Object
    using MatrixDistance = std::function<void(const void *m, const void *q,
                                              size_t dim, float *out)>;

    //! Destructor
    virtual ~IndexMeasure(void) {}

    //! Initialize Measure
    virtual int init(const IndexMeta &meta, const IndexParams &params) = 0;

    //! Cleanup Measure
    virtual int cleanup(void) = 0;

    //! Retrieve if it matched
    virtual bool is_matched(const IndexMeta &meta) const = 0;

    //! Retrieve if it matched
    virtual bool is_matched(const IndexMeta &meta,
                            const IndexQueryMeta &qmeta) const = 0;

    //! Retrieve distance function for query
    virtual MatrixDistance distance(void) const = 0;

    //! Retrieve distance function for index features
    virtual MatrixDistance distance_matrix(size_t m, size_t n) const = 0;

    //! Normalize result
    virtual void normalize(float *score) const
    {
        (void)score;
    }

    //! Retrieve if it supports normalization
    virtual bool support_normalize(void) const
    {
        return false;
    }

    //! Compute the distance between feature and query
    float distance(const void *m, const void *q, size_t dim) const
    {
        float dist;
        (this->distance())(m, q, dim, &dist);
        return dist;
    }
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_MEASURE_H__
