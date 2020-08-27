/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_searcher.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  1.0.0
 *   \brief    Interface of AiTheta Index Searcher
 */

#ifndef __AITHETA2_INDEX_SEARCHER_H__
#define __AITHETA2_INDEX_SEARCHER_H__

#include "index_container.h"
#include "index_context.h"
#include "index_measure.h"
#include "index_provider.h"
#include "index_stats.h"

namespace aitheta2 {

/*! Index Searcher
 */
class IndexSearcher : public IndexModule
{
public:
    //! Index Searcher Pointer
    typedef std::shared_ptr<IndexSearcher> Pointer;

    /*! Index Searcher Stats
     */
    class Stats : public IndexStats
    {
    public:
        //! Set count of documents loaded
        void set_loaded_count(size_t count)
        {
            loaded_count_ = count;
        }

        //! Set time cost of documents loaded
        void set_loaded_costtime(uint64_t cost)
        {
            loaded_costtime_ = cost;
        }

        //! Retrieve count of documents loaded
        size_t loaded_count(void) const
        {
            return loaded_count_;
        }

        //! Retrieve time cost of documents loaded
        uint64_t loaded_costtime(void) const
        {
            return loaded_costtime_;
        }

        //! Retrieve count of documents loaded (mutable)
        size_t *mutable_loaded_count(void)
        {
            return &loaded_count_;
        }

        //! Retrieve time cost of documents loaded (mutable)
        uint64_t *mutable_loaded_costtime(void)
        {
            return &loaded_costtime_;
        }

    private:
        //! Members
        size_t loaded_count_{ 0u };
        uint64_t loaded_costtime_{ 0u };
    };

    /*! Index Searcher Context
     */
    struct Context : public IndexContext
    {
    };

    /*! Index Searcher Provider
     */
    struct Provider : public IndexProvider
    {
    };

    //! Destructor
    virtual ~IndexSearcher(void) {}

    //! Initialize Searcher
    virtual int init(const IndexParams &params) = 0;

    //! Cleanup Searcher
    virtual int cleanup(void) = 0;

    //! Load index from container
    virtual int load(const IndexContainer::Pointer &cntr,
                     const IndexMeasure::Pointer &measure) = 0;

    //! Unload index
    virtual int unload(void) = 0;

    //! Similarity brute force search
    virtual int search_bf_impl(const void *query, const IndexQueryMeta &qmeta,
                               Context::Pointer &context) const = 0;

    //! Similarity search
    virtual int search_impl(const void *query, const IndexQueryMeta &qmeta,
                            Context::Pointer &context) const = 0;

    //! Similarity brute force search
    virtual int search_bf_impl(const void *query, const IndexQueryMeta &qmeta,
                               uint32_t count,
                               Context::Pointer &context) const = 0;

    //! Similarity search
    virtual int search_impl(const void *query, const IndexQueryMeta &qmeta,
                            uint32_t count,
                            Context::Pointer &context) const = 0;

    //! Retrieve statistics
    virtual const Stats &stats(void) const = 0;

    //! Retrieve meta of index
    virtual const IndexMeta &meta(void) const = 0;

    //! Create a searcher context
    virtual Context::Pointer create_context(void) const = 0;

    //! Create a searcher provider
    virtual Provider::Pointer create_provider(void) const
    {
        return Provider::Pointer();
    }

    //! Similarity search (FP32)
    template <IndexMeta::FeatureTypes FT, typename = typename std::enable_if<
                                              FT == IndexMeta::FT_FP32>::type>
    int search(const float *vec, size_t dim, Context::Pointer &context) const
    {
        return this->search_impl(vec, IndexQueryMeta(FT, dim), context);
    }
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_SEARCHER_H__
