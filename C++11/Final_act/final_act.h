// Copyright (c) 2019 Matthias Deimbacher
// Licensed under MIT License
//
// Core Guideline
// E.19: Use a final_action object to express cleanup if no suitable resource handle is available
//
// Based on the articles of Bartłomiej Filipek and Rainer Grimms
//
// https://www.bfilipek.com/2017/04/finalact.html 
// https://www.heise.de/developer/artikel/C-Core-Guidelines-finally-in-C-4133759.html
// http://www.modernescpp.com/index.php/c-core-guidelines-when-you-can-t-throw-an-exception
//

#pragma once

template <class F>
class final_act
{
public:
    explicit final_act(F f) noexcept 
      : f_(std::move(f)), invoke_(true) {}

    final_act(final_act&& other) noexcept 
     : f_(std::move(other.f_)), 
       invoke_(other.invoke_)
    {
        other.invoke_ = false;
    }

    final_act(const final_act&) = delete;
    final_act& operator=(const final_act&) = delete;

    ~final_act() noexcept
    {
        if (invoke_) f_();
    }

private:
    F f_;
    bool invoke_;
};

// Before C++17 this is needed for easier use, because there is no template argument deduction for template classes
template <class F>
inline final_act<F> finally(const F& f) noexcept
{
    return final_act<F>(f);
}

template <class F>
inline final_act<F> finally(F&& f) noexcept
{
    return final_act<F>(std::forward<F>(f));
}