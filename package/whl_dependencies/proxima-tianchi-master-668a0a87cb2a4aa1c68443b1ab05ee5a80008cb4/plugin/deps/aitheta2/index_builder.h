/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_builder.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  2.0.0
 *   \brief    Interface of AiTheta Index Builder
 */

#ifndef __AITHETA2_INDEX_BUILDER_H__
#define __AITHETA2_INDEX_BUILDER_H__

#include "index_dumper.h"
#include "index_holder.h"
#include "index_meta.h"
#include "index_stats.h"
// #include "index_trainer.h"

namespace aitheta2 {

/*! Index Builder
 */
class IndexBuilder : public IndexModule
{
public:
    //! Index Builder Pointer
    typedef std::shared_ptr<IndexBuilder> Pointer;

    /*! Index Builder Stats
     */
    class Stats : public IndexStats
    {
    public:
        //! Set count of documents trained
        void set_trained_count(size_t count)
        {
            trained_count_ = count;
        }

        //! Set count of documents built
        void set_built_count(size_t count)
        {
            built_count_ = count;
        }

        //! Set count of documents dumped
        void set_dumped_count(size_t count)
        {
            dumped_count_ = count;
        }

        //! Set count of documents discarded
        void set_discarded_count(size_t count)
        {
            discarded_count_ = count;
        }

        //! Set time cost of documents trained
        void set_trained_costtime(uint64_t cost)
        {
            trained_costtime_ = cost;
        }

        //! Set time cost of documents built
        void set_built_costtime(uint64_t cost)
        {
            built_costtime_ = cost;
        }

        //! Set time cost of documents dumped
        void set_dumped_costtime(uint64_t cost)
        {
            dumped_costtime_ = cost;
        }

        //! Retrieve count of documents trained
        size_t trained_count(void) const
        {
            return trained_count_;
        }

        //! Retrieve count of documents built
        size_t built_count(void) const
        {
            return built_count_;
        }

        //! Retrieve count of documents dumped
        size_t dumped_count(void) const
        {
            return dumped_count_;
        }

        //! Retrieve count of documents discarded
        size_t discarded_count(void) const
        {
            return discarded_count_;
        }

        //! Retrieve time cost of documents trained
        uint64_t trained_costtime(void) const
        {
            return trained_costtime_;
        }

        //! Retrieve time cost of documents built
        uint64_t built_costtime(void) const
        {
            return built_costtime_;
        }

        //! Retrieve time cost of documents dumped
        uint64_t dumped_costtime(void) const
        {
            return dumped_costtime_;
        }

        //! Retrieve count of documents trained (mutable)
        size_t *mutable_trained_count(void)
        {
            return &trained_count_;
        }

        //! Retrieve count of documents built (mutable)
        size_t *mutable_built_count(void)
        {
            return &built_count_;
        }

        //! Retrieve count of documents dumped (mutable)
        size_t *mutable_dumped_count(void)
        {
            return &dumped_count_;
        }

        //! Retrieve count of documents discarded (mutable)
        size_t *mutable_discarded_count(void)
        {
            return &discarded_count_;
        }

        //! Retrieve time cost of documents trained (mutable)
        uint64_t *mutable_trained_costtime(void)
        {
            return &trained_costtime_;
        }

        //! Retrieve time cost of documents built (mutable)
        uint64_t *mutable_built_costtime(void)
        {
            return &built_costtime_;
        }

        //! Retrieve time cost of documents dumped (mutable)
        uint64_t *mutable_dumped_costtime(void)
        {
            return &dumped_costtime_;
        }

    private:
        //! Members
        size_t trained_count_{ 0u };
        size_t built_count_{ 0u };
        size_t dumped_count_{ 0u };
        size_t discarded_count_{ 0u };
        uint64_t trained_costtime_{ 0u };
        uint64_t built_costtime_{ 0u };
        uint64_t dumped_costtime_{ 0u };
    };

    //! Destructor
    virtual ~IndexBuilder(void) {}

    //! Initialize the builder
    virtual int init(const IndexMeta &meta, const IndexParams &params) = 0;

    //! Cleanup the builder
    virtual int cleanup(void) = 0;

    //! Train the data
    virtual int train(const IndexHolder::Pointer &holder) = 0;

    //! Train the data
    virtual int train(void)
    {
        return 0;
    }

    //! Build the index
    virtual int build(const IndexHolder::Pointer &holder) = 0;

    //! Dump index into storage
    virtual int dump(const IndexDumper::Pointer &dumper) = 0;

    //! Retrieve statistics
    virtual const Stats &stats(void) const = 0;
    // virtual const Stats &stats(void) const
    // {
    //     return Stats();
    // }

    //! Train and build the index
    static int TrainAndBuild(const IndexBuilder::Pointer &builder,
                             const IndexHolder::Pointer &holder);

    //! Train, build and dump the index
    static int TrainBuildAndDump(const IndexBuilder::Pointer &builder,
                                 const IndexHolder::Pointer &holder,
                                 const IndexDumper::Pointer &dumper);
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_BUILDER_H__
