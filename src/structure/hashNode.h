template<typename K, typename V>

class hashNode
{
  private:
    K key;
    V value;
    hashNode *next;
  public:
    hashNode(const K &key, const V &value) : key(key), value(value), next(NULL){}
    K getKey() const { return key; }

    V getValue() const { return value; }

    void setvalue(V value) { hashNode::value = value; }

    hashNode *getNext() const { return next; }

    void setNext(hashNode *next) { hashNode::next = next; }
};
