/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_context.h
 *   \author   Hechong.xyf
 *   \date     Oct 2019
 *   \version  2.0.0
 *   \brief    Interface of AiTheta Index Context
 */

#ifndef __AITHETA2_INDEX_CONTEXT_H__
#define __AITHETA2_INDEX_CONTEXT_H__

#include "index_document.h"
#include "index_error.h"
#include "index_params.h"
#include <functional>
#include <memory>

namespace aitheta2 {

/*! Index Filter
 */
class IndexFilter {
 //! You can add filter if you like
 private:
  //! Members
  std::function<bool(uint64_t key)> filter_{};
};

/*! Index Context
 */
class IndexContext
{
public:
    //! Index Context Pointer
    typedef std::unique_ptr<IndexContext> Pointer;

    //! Destructor
    virtual ~IndexContext(void) {}

    //! Set topk of search result
    virtual void set_topk(uint32_t topk) = 0;

    //! Set mode of debug
    virtual void set_debug_mode(bool /*enable*/) {}

    //! Retrieve search result
    virtual const IndexDocumentList &result(void) const = 0;

    //! Retrieve search result with index
    virtual const IndexDocumentList &result(size_t /*index*/) const
    {
        return this->result();
    }

    //! Update the parameters of context
    virtual int update(const IndexParams & /*params*/)
    {
        return IndexError_NotImplemented;
    }

    //! Retrieve mode of debug
    virtual bool debug_mode(void) const
    {
        return false;
    }

    //! Retrieve debug information
    virtual std::string debug_string(void) const
    {
        return std::string();
    }

    //! Retrieve magic number
    virtual uint32_t magic(void) const
    {
        return 0;
    }

    //! Set threshold for RNN
    void set_threshold(float val)
    {
        threshold_ = val;
    }

    //! Retrieve value of threshold for RNN
    float threshold(void) const
    {
        return threshold_;
    }

private:
    //! Members
    IndexFilter filter_{};
    float threshold_{ std::numeric_limits<float>::max() };
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_CONTEXT_H__
