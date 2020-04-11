template <typename item> using default_list = insertable<list<item>>;
template <typename key> using default_set = searchable<set<key>>;
template <typename key, typename value> using default_map = searchable<map<key,value>>;

