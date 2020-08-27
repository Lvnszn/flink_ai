#ifndef __PROXIMA2_PLUGIN_EXAMPLE_BUILD_H__
#define __PROXIMA2_PLUGIN_EXAMPLE_BUILD_H__

#include <index_framework.h>
#include <string>
#include <vector>

/*! Example Builder
 */
namespace proxima2 {
namespace example {

class ExampleBuilder : public aitheta2::IndexBuilder
{
public:
    //! Constructor
    ExampleBuilder(void) {}

    virtual ~ExampleBuilder() {}

    ExampleBuilder(const ExampleBuilder &LinearBuilder) = delete;
    ExampleBuilder &operator=(const ExampleBuilder &clusteringBuilder) = delete;

protected:
    //! Initialize Builder
    virtual int init(const aitheta2::IndexMeta &meta,
                     const aitheta2::IndexParams &params) override;

    //! Cleanup Builder
    virtual int cleanup(void) override;

    //! Train the data
    virtual int train(const aitheta2::IndexHolder::Pointer &holder) override
    {
        if (!holder.get()) {
            LOG_ERROR("Index holder is in invalid");
            return aitheta2::IndexError_InvalidArgument;
        }

        return 0;
    }

    //! Build the index
    virtual int build(const aitheta2::IndexHolder::Pointer &holder) override;

    //! Dump index into file path or dir
    virtual int dump(const aitheta2::IndexDumper::Pointer &dumper) override;

    //! Retrieve statistics
    virtual const Stats &stats(void) const override
    {
        return stats_;
    }

private:
    aitheta2::IndexMeta meta_;
    Stats stats_;
    aitheta2::IndexHolder::Pointer holder_;
};

} // namespace example
} // namespace proxima2
#endif //__PROXIMA2_PLUGIN_EXAMPLE_BUILD_H__
