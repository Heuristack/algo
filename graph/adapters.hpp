template <typename container>
struct adapter : container
{
    using base_type = container;
    using value_type = typename base_type::value_type;
    auto get() -> value_type
    {
        value_type v;
        if constexpr (is_same<base_type,stack<value_type>>::value) { v = base_type::top();   }
        if constexpr (is_same<base_type,queue<value_type>>::value) { v = base_type::front(); }
        base_type::pop();
        return v;
    }
    auto put(value_type const & v)
    {
        base_type::push(v);
    }
};

