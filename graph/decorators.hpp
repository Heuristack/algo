template <typename container>
struct searchable : container
{
    auto contains(typename container::key_type const & k) const { return container::find(k) != container::end(); } // note : C++20 feature!
    auto get(typename container::key_type & k) -> typename container::value_type & { return *container::find(k); }
};

template <typename container>
struct insertable : container
{
    auto insert(typename container::value_type const & v) { return container::push_back(v); }
};

