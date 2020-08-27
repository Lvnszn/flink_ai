/**
 *   Copyright (C) The Software Authors. All rights reserved.

 *   \file     index_document.h
 *   \author   Alibaba-tianchi
 *   \date     July 2020
 *   \version  2.0.0
 *   \brief    Interface of AiTheta Index Document
 */

#ifndef __AITHETA2_INDEX_DOCUMENT_H__
#define __AITHETA2_INDEX_DOCUMENT_H__

namespace aitheta2 {

/*! Index Document
 */
class IndexDocument
{
public:
    //! Constructor
    IndexDocument(uint64_t k, float v) : key_(k), score_(v) {}

    //! Constructor
    IndexDocument(uint64_t k, float v, uint32_t i)
        : key_(k), score_(v), index_(i)
    {
    }

    //! Constructor
    IndexDocument(const IndexDocument &rhs)
        : key_(rhs.key_), score_(rhs.score_), index_(rhs.index_)
    {
    }

    //! Assignment
    IndexDocument &operator=(const IndexDocument &rhs)
    {
        key_ = rhs.key_;
        score_ = rhs.score_;
        index_ = rhs.index_;
        return *this;
    }

    //! Less than
    bool operator<(const IndexDocument &rhs) const
    {
        return (this->score_ < rhs.score_);
    }

    //! Greater than
    bool operator>(const IndexDocument &rhs) const
    {
        return (this->score_ > rhs.score_);
    }

    //! Retrieve primary key
    uint64_t key(void) const
    {
        return key_;
    }

    //! Retrieve score value
    float score(void) const
    {
        return score_;
    }

    //! Retrieve index id
    uint32_t index(void) const
    {
        return index_;
    }

    //! Retrieve mutable primary key
    uint64_t *mutable_key(void)
    {
        return &key_;
    }

    //! Retrieve mutable score value
    float *mutable_score(void)
    {
        return &score_;
    }

    //! Retrieve mutable index id
    uint32_t *mutable_index(void)
    {
        return &index_;
    }

    //! Retrieve primary key
    void set_key(uint64_t val)
    {
        key_ = val;
    }

    //! Retrieve score value
    void set_score(float val)
    {
        score_ = val;
    }

    //! Retrieve index id
    void set_index(uint32_t val)
    {
        index_ = val;
    }

private:
    //! Data members
    uint64_t key_{ 0u };
    float score_{ 0.0f };
    uint32_t index_{ 0u };
};

/*! Index Document List
 */
using IndexDocumentList = std::vector<IndexDocument>;

} // namespace aitheta2

#endif // __AITHETA2_INDEX_DOCUMENT_H__
