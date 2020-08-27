#include "plugin_build.h"
#include <iostream>

namespace proxima2 {
namespace example {

//! Initialize Builder
int ExampleBuilder::init(const aitheta2::IndexMeta &meta,
                         const aitheta2::IndexParams &params)
{
    std::cout << "[tips]: Do your builder init here" << std::endl;
    return 0;
}

//! Cleanup Builder
int ExampleBuilder::cleanup()
{
    std::cout << "[tips]: Do your cleanup resources here" << std::endl;
    return 0;
}

//! Build the index
int ExampleBuilder::build(const aitheta2::IndexHolder::Pointer &holder)
{
    std::cout << "[tips]: Build index here" << std::endl;
    return 0;
}

//! Dump index into file path or dir
int ExampleBuilder::dump(const aitheta2::IndexDumper::Pointer &dumper)
{
    std::cout << "[tips]: Dump index to file here" << std::endl;
    return 0;
}

INDEX_FACTORY_REGISTER_BUILDER(ExampleBuilder);
} // namespace example
} // namespace proxima2
