#ifndef __PROXIMA2_LINEAR_SEARCH_H__
#define __PROXIMA2_LINEAR_SEARCH_H__

#include <aitheta2/index_framework.h>
#include <string>
#include <vector>

namespace proxima2 {
namespace example {

class ExampleSearcher : public aitheta2::IndexSearcher
{
public:
    //! Constructor
    ExampleSearcher(void) {}

    //! Destructor
    virtual ~ExampleSearcher() {}

    ExampleSearcher(const ExampleSearcher &) = delete;
    ExampleSearcher &operator=(const ExampleSearcher &) = delete;

    //! Initialize Searcher
    virtual int init(const aitheta2::IndexParams &params) override;

    //! Cleanup Searcher
    virtual int cleanup(void) override;

    //! Load index from container
    virtual int load(const aitheta2::IndexContainer::Pointer &container,
                     const aitheta2::IndexMeasure::Pointer &measure) override;

    //! Unload index
    virtual int unload(void) override;

    //! Similarity brute force search
    virtual int search_bf_impl(const void *query,
                               const aitheta2::IndexQueryMeta &qmeta,
                               Context::Pointer &context) const override
    {
        return search_impl(query, qmeta, context);
    }

    //! Similarity brute force search
    virtual int search_bf_impl(const void *query,
                               const aitheta2::IndexQueryMeta &qmeta,
                               uint32_t count,
                               Context::Pointer &context) const override
    {
        return search_impl(query, qmeta, count, context);
    }

    //! Similarity search
    virtual int search_impl(const void *query,
                            const aitheta2::IndexQueryMeta &qmeta,
                            Context::Pointer &context) const override
    {
        return search_impl(query, qmeta, 1, context);
    }

    //! Similarity search
    virtual int search_impl(const void *query,
                            const aitheta2::IndexQueryMeta &qmeta,
                            uint32_t count,
                            Context::Pointer &context) const override;

    //! Retrieve statistics
    virtual const Stats &stats(void) const override;

    //! Create a searcher context
    virtual Context::Pointer create_context(void) const override
    {
        return nullptr;
    }

    //! Retrieve meta of index
    virtual const aitheta2::IndexMeta &meta(void) const override
    {
        return meta_;
    }

    aitheta2::IndexSearcher::Provider::Pointer
    create_provider(void) const override;

private:
    //! Members
    aitheta2::IndexMeta meta_;
    Stats stats_;
};

} // namespace example
} // namespace proxima2

#endif //__PROXIMA2_EXAMPLE_SEARCH_H__
