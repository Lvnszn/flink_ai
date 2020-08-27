#include "plugin_searcher.h"
#include <iostream>

namespace proxima2 {
namespace example {

//! Initialize Searcher
int ExampleSearcher::init(const aitheta2::IndexParams &params)
{
    std::cout << "[tips]: Do your searcher init here" << std::endl;
    return 0;
}

//! Cleanup Searcher
int ExampleSearcher::cleanup(void)
{
    std::cout << "[tips]: Do your cleanup resources here" << std::endl;
    return 0;
}

//! Load index from container
int ExampleSearcher::load(const aitheta2::IndexContainer::Pointer &container,
                          const aitheta2::IndexMeasure::Pointer &measure)
{
    std::cout << "[tips]: Load index here" << std::endl;
    std::cout
        << "[tips]: You need create context yourself, if you want to continue"
        << std::endl;
    return 0;
}

//! Unload index
int ExampleSearcher::unload(void)
{
    return 0;
}

//! Similarity search
int ExampleSearcher::search_impl(const void *query,
                                 const aitheta2::IndexQueryMeta &,
                                 uint32_t count,
                                 Context::Pointer &context) const

{
    std::cout << "[tips]: You can implement search here" << std::endl;
    return 0;
}


const aitheta2::IndexSearcher::Stats &ExampleSearcher::stats(void) const
{
    return stats_;
}

aitheta2::IndexSearcher::Provider::Pointer
ExampleSearcher::create_provider(void) const
{
    return nullptr;
}

INDEX_FACTORY_REGISTER_SEARCHER(ExampleSearcher);
} // namespace example
} // namespace proxima2
