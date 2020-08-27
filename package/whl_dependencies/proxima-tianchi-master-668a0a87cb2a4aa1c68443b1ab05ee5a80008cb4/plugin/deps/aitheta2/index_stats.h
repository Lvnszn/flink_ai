/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_stats.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  1.0.0
 *   \brief    Interface of AiTheta Index Stats
 */

#ifndef __AITHETA2_INDEX_STATS_H__
#define __AITHETA2_INDEX_STATS_H__

#include "index_params.h"

namespace aitheta2 {

/*! Index Stats
 */
class IndexStats
{
public:
    //! Test if the element is exist
    bool has_attribute(const std::string &key) const
    {
        return attributes_.has(key);
    }

    //! Set the value of key in T
    template <typename T>
    bool set_attribute(const std::string &key, T &&val)
    {
        return attributes_.set<T>(key, std::forward<T>(val));
    }

    //! Retrieve attribute with key
    template <typename T>
    bool get_attribute(const std::string &key, T *out) const
    {
        return attributes_.get<T>(key, out);
    }

    //! Erase the pair via a key
    bool erase_attribute(const std::string &key)
    {
        return attributes_.erase(key);
    }

    //! Clear the attributes
    void clear_attributes(void)
    {
        attributes_.clear();
    }

    //! Retrieve attributes
    const IndexParams &attributes(void) const
    {
        return attributes_;
    }

    //! Retrieve mutable attributes
    IndexParams *mutable_attributes(void)
    {
        return &attributes_;
    }

private:
    //! Members
    IndexParams attributes_{};
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_STATS_H__
