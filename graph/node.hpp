template <typename vertex>
struct node
{
    using this_type = node<vertex>;
    using vertex_type = vertex;
    node(vertex_type const & v) : v(v) {}
    node() = default;
    bool operator < (this_type const & that) const { return v < that.v; }       // TODO: vertex concept requires order relation
    vertex_type v{};
};

