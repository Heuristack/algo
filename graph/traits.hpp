template <typename> struct is_weighted {};
template <typename vertex> struct is_weighted<edge<vertex>> { static bool constexpr value = false; };
template <typename vertex, typename ... weight> struct is_weighted<edge<vertex,weight...>> { static bool constexpr value = true; };

