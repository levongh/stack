#pragma once

#include <vector>

template<typename T, typename container = std::vector<T> >
class stack
{
public:
    using value_type = typename container::value_type;
    using reference = typename container::reference;
    using const_reference = typename container::const_reference;
    using size_type = typename container::size_type;

public:
    explicit stack(const container& c = container())
        : m_cont{c}
    {
    }

    inline bool empty() const
    {
        return m_cont.empty();
    }

    inline size_type size() const
    {
        return m_cont.size();
    }

    reference top()
    {
        return m_cont.back();
    }

    const_reference top() const
    {
        return m_cont.back();
    }

    void push(const value_type& val)
    {
        m_cont.push_back(std::move(val));
    }

    void push(value_type&& val)
    {
        m_cont.push_back(std::move(val));
    }

    template <typename ... Args>
    void emplace(Args&&... args)
    {
        m_cont.emplace_back(std::forward<Args>(args)...);
    }

    void pop()
    {
        m_cont.pop_back();
    }

    void swap(stack&& st)
    {
        m_cont.swap(st.m_cont);
    }

    inline bool operator==(const stack& rhs) const
    {
        return m_cont == rhs.m_cont;
    }

    inline bool operator!=(const stack& rhs)
    {
        return m_cont != rhs.m_cont;
    }

private:
    container m_cont;
};
