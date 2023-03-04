template <class X, class Y>
ostream & operator << (ostream & os, pair <X, Y> const& p) {
    return os << "[" << p.first << ", " << p.second << "]" ;
}

template<typename T>
void print(T input, string name="") {
    cout << name << endl;
    for (auto elem: input) cout << elem << " ";
    cout << endl;
}

template<typename T>
void print2D(T input, string name="") {
    cout << name << endl;
    for (auto row: input) {
        for (auto elem: row) cout << elem << " ";
        cout << endl;
    }
    cout << endl;
}

template<typename T>
void print3D(T input, string name="") {
    cout << name << endl;
    for (auto row: input) {
        for (auto column: row) {
            for (auto elem: column) cout << elem << " ";
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
}