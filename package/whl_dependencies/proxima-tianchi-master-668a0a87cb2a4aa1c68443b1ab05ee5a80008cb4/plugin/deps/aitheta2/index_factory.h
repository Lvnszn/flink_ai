/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_factory.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  1.0.0
 *   \brief    Interface of AiTheta Index Factory
 */

#ifndef __AITHETA2_INDEX_FACTORY_H__
#define __AITHETA2_INDEX_FACTORY_H__

#include "index_builder.h"
#include "index_dumper.h"
#include "index_searcher.h"
#include "factory.h"

namespace aitheta2 {

/*! Index Factory
 */
struct IndexFactory
{

    //! Create a index dumper by name
    static IndexDumper::Pointer CreateDumper(const std::string &name);

    //! Test if the dumper is exist
    static bool HasDumper(const std::string &name);

    //! Create a index builder by name
    static IndexBuilder::Pointer CreateBuilder(const std::string &name);

    //! Test if the builder is exist
    static bool HasBuilder(const std::string &name);

    //! Create a index searcher by name
    static IndexSearcher::Pointer CreateSearcher(const std::string &name);

    //! Test if the searcher is exist
    static bool HasSearcher(const std::string &name);
};

//! Register Index Dumper
#define INDEX_FACTORY_REGISTER_DUMPER_ALIAS(__NAME__, __IMPL__, ...)           \
    AILEGO_FACTORY_REGISTER(__NAME__, aitheta2::IndexDumper, __IMPL__,         \
                            ##__VA_ARGS__)

//! Register Index Dumper
#define INDEX_FACTORY_REGISTER_DUMPER(__IMPL__, ...)                           \
    INDEX_FACTORY_REGISTER_DUMPER_ALIAS(__IMPL__, __IMPL__, ##__VA_ARGS__)

//! Register Index Builder
#define INDEX_FACTORY_REGISTER_BUILDER_ALIAS(__NAME__, __IMPL__, ...)          \
    AILEGO_FACTORY_REGISTER(__NAME__, aitheta2::IndexBuilder, __IMPL__,        \
                            ##__VA_ARGS__)

//! Register Index Builder
#define INDEX_FACTORY_REGISTER_BUILDER(__IMPL__, ...)                          \
    INDEX_FACTORY_REGISTER_BUILDER_ALIAS(__IMPL__, __IMPL__, ##__VA_ARGS__)

//! Register Index Searcher
#define INDEX_FACTORY_REGISTER_SEARCHER_ALIAS(__NAME__, __IMPL__, ...)         \
    AILEGO_FACTORY_REGISTER(__NAME__, aitheta2::IndexSearcher, __IMPL__,       \
                            ##__VA_ARGS__)

//! Register Index Searcher
#define INDEX_FACTORY_REGISTER_SEARCHER(__IMPL__, ...)                         \
    INDEX_FACTORY_REGISTER_SEARCHER_ALIAS(__IMPL__, __IMPL__, ##__VA_ARGS__)

} // namespace aitheta2

#endif // __AITHETA2_INDEX_FACTORY_H__
