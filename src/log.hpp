#ifndef __LOG_HPP__
#define __LOG_HPP__

#include "color.hpp"
#include <iostream>
#include <string>

void log(const std::string&, const std::string&);
void err(const std::string&, const std::string&);

/**
 * @brief ログを標準出力に表示します．
 * @param [in] func 関数名
 * @param [in] msg 表示メッセージ
 */
void log(const std::string& func, const std::string& msg) {
    std::cout << "[" CYAN << func << PLAIN "] " << msg << "\n" << std::endl;
}

/**
 * @brief ログを標準エラー出力に表示します．
 * @param [in] func 関数名
 * @param [in] msg 表示メッセージ
 */
void err(const std::string& func, const std::string& msg) {
    std::cout << "[" RED << func << PLAIN "] " << msg << "\n" << std::endl;
}

#endif