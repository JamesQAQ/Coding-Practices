class OrderedStream {
private:
  vector<string> stream;
  int ptr;

public:
  OrderedStream(int n) {
    stream = vector<string>(n, "");
    ptr = 0;
  }

  vector<string> insert(int idKey, string value) {
    vector<string> result;
    stream[idKey - 1] = value;
    while (ptr < stream.size() && stream[ptr].length() != 0) {
      result.push_back(stream[ptr++]);
    }
    return result;
  }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
