/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_plugin.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  1.0.0
 *   \brief    Interface of AiTheta Index Plugin
 */

#ifndef __AITHETA2_INDEX_PLUGIN_H__
#define __AITHETA2_INDEX_PLUGIN_H__

#include <string>
#include <vector>

namespace aitheta2 {

/*! Index Plugin
 */
class IndexPlugin
{
public:
    //! Constructor
    IndexPlugin(void) : handle_(nullptr) {}

    //! Constructor
    IndexPlugin(IndexPlugin &&plugin) : handle_(plugin.handle_)
    {
        plugin.handle_ = nullptr;
    }

    //! Constructor
    explicit IndexPlugin(const std::string &path) : handle_(nullptr)
    {
        this->load(path);
    }

    //! Destructor
    ~IndexPlugin(void) {}

    //! Test if the plugin is valid
    bool is_valid(void) const
    {
        return (!!handle_);
    }

    //! Retrieve the handle
    void *handle(void) const
    {
        return handle_;
    }

    //! Load the library path
    bool load(const std::string &path);

    //! Load the library path
    bool load(const std::string &path, std::string *err);

    //! Unload plugin
    void unload(void);

private:
    //! Disable them
    IndexPlugin(const IndexPlugin &) = delete;
    IndexPlugin &operator=(const IndexPlugin &) = delete;

    //! Members
    void *handle_;
};

/*! Index Plugin Broker
 */
class IndexPluginBroker
{
public:
    //! Constructor
    IndexPluginBroker(void) : plugins_() {}

    //! Constructor
    IndexPluginBroker(IndexPluginBroker &&broker)
        : plugins_(std::move(broker.plugins_))
    {
    }

    //! Destructor
    ~IndexPluginBroker(void) {}

    //! Emplace a plugin
    bool emplace(IndexPlugin &&plugin);

    //! Emplace a plugin via library path
    bool emplace(const std::string &path)
    {
        return this->emplace(IndexPlugin(path));
    }

    //! Emplace a plugin via library path
    bool emplace(const std::string &path, std::string *err)
    {
        aitheta2::IndexPlugin plugin;
        if (!plugin.load(path, err)) {
            return false;
        }
        return this->emplace(std::move(plugin));
    }

    //! Load plugins into broker (with pattern)
    bool load(const std::string &pattern);

    //! Retrieve count of plugins in broker
    size_t count(void) const
    {
        return plugins_.size();
    }

private:
    //! Disable them
    IndexPluginBroker(const IndexPluginBroker &) = delete;
    IndexPluginBroker &operator=(const IndexPluginBroker &) = delete;

    //! Members
    std::vector<IndexPlugin> plugins_;
};

} // namespace aitheta2

#endif // __AITHETA2_INDEX_PLUGIN_H__
