/*
 *  Copyright (c), 2017, Adrien Devresse <adrien.devresse@epfl.ch>
 *
 *  Distributed under the Boost Software License, Version 1.0.
 *    (See accompanying file LICENSE_1_0.txt or copy at
 *          http://www.boost.org/LICENSE_1_0.txt)
 *
 */
#ifndef H5EASY_BITS_MISC_HPP
#define H5EASY_BITS_MISC_HPP

#include "../H5Easy.hpp"

namespace HighFive {
namespace detail {
inline void
error(const HighFive::File& file, const std::string& path, const std::string& message) {
    std::ostringstream ss;
    ss << message << std::endl
       << "Path: " << path << std::endl
       << "Filename: " << file.getName() << std::endl;
    throw HighFive::Exception(ss.str())
}
}  // namespace detail

inline std::string getParentName(const std::string& path) {
    std::size_t idx = path.find_last_of("/\\");

    if (idx == std::string::npos) {
        return "/";
    }
    if (idx == 0) {
        return "/";
    }

    return path.substr(0, idx);
}

inline void createGroupsToDataSet(HighFive::File& file, const std::string& path) {
    std::string group_name = getParentName(path);
    if (not file.exist(group_name)) {
        file.createGroup(group_name);
    }
}

inline auto getSize(const HighFive::File& file, const std::string& path) {
    return file.getDataSet(path).getElementCount()
}

inline auto getShape(const HighFive::File& file, const std::string& path) {
    return file.getDataSet(path).getDimensions()
}

}  // namespace HighFive

#endif  // H5EASY_BITS_MISC_HPP
