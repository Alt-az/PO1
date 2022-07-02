#ifndef __MAP_TEMPLATE_H__
#define __MAP TEMPLATE_H__


using namespace std;
template <class Key, class Value> class map_template {
  private:
	struct node {
		node* next;
		Key* key;
		Value* val;
		node(const Key k) : next(NULL) {
			key = new Key(k);
		};
		~node() {
			delete val;
			delete key;
		}
		node(const node& s) : next(NULL) {
			if (s.key == NULL)
				key = NULL;
			else {
				key = new Key(*s.key);
			}
			val=new Value(*s.val);
		};

	  private: // assignment not allowed
		node& operator=(const node&);
	};
	node* head;

  public:
	map_template() { head = NULL; }

	void clear() {
		while (head) {
			node* t = head->next;
			delete head;
			head = t;
		};
	}

	~map_template() { clear(); }

	void Add(const Key key, Value value) {
		node* newnode = new node(key);
		newnode->next = head;
		head = newnode;
		head->val = new Value(value);
	}

	void swap(map_template<Key, Value>& l) {
		node* t = head;
		head = l.head;
		l.head = t;
	}

	map_template(const map_template<Key, Value>& l) {
		node *src, **dst;
		head = NULL;
		src = l.head;
		dst = &head;
		try {
			while (src) {
				*dst = new node(*src);
				src = src->next;
				dst = &((*dst)->next);
			}
		} catch (...) {
			clear();
			throw;
		};
	}

	map_template& operator=(const map_template<Key, Value>& l) {
		if (&l == this)
			return *this;
		map_template t(l);
		swap(t);
		return *this;
	}

	Value* Find(const Key key) const {
		node* c = head;
		while (c) {
			if (*(c->key) == key)
				return c->val;
			c = c->next;
		};
		return NULL;
	}

	friend ostream& operator<<(ostream& o, const map_template<Key, Value>& v) {
		node* t = v.head;
		while (t) {
			o << "Key: " << *(t->key);
			o << *(t->val);
			o << endl;
			t = t->next;
		}
		return o;
	}
};

#endif /* __MAP_TEMPLATE_H__ */
