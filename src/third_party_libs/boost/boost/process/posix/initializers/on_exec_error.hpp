// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

/**
 * \file boost/process/posix/initializers/on_exec_error.hpp
 *
 * Defines a generic handler called after exec failed.
 */

#ifndef BOOST_PROCESS_POSIX_INITIALIZERS_ON_EXEC_ERROR_HPP
#define BOOST_PROCESS_POSIX_INITIALIZERS_ON_EXEC_ERROR_HPP

#include <boost/process/config.hpp>
#include <boost/process/posix/initializers/initializer_base.hpp>

namespace boost { namespace process { namespace posix { namespace initializers {

template <class Handler>
class on_exec_error_ : public initializer_base
{
public:
    explicit on_exec_error_(Handler handler) : handler_(handler) {}

    template <class PosixExecutor>
    void on_exec_error(PosixExecutor &e) const
    {
        handler_(e);
    }

private:
    Handler handler_;
};

template <class Handler>
on_exec_error_<Handler> on_exec_error(Handler handler)
{
    return on_exec_error_<Handler>(handler);
}

}}}}

#endif
