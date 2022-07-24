#include<vector>
#include<string>
#include<priority_queue>

using namespace std;

class LongestHappyStringFinder {
public:
	struct charPair {
		charPair(char c, int cnt): ch(c), count(cnt) {}
		char ch;
		int count;
	};

	struct compareCharPair {
		bool operator()(charPair const& p1, charPair const& p2) {
			return p1.count <= p2.count;
		}
	};

	bool canInsert(string str, char ch) {
		int size = str.length();
		if (size < 2)   return true;
		// str >=2
		char c1 = str[size - 1], c2 = str[size - 2];
		if (c1 == c2 && c2 == ch) return false;
		return true;
	}

	string longestDiverseString(int a, int b, int c) {
		priority_queue<charPair, vector<charPair>, compareCharPair> p_q;
		string out_string = "";
		// Creating the Character-Pair(s).
		charPair p_a('a', a);
		charPair p_b('b', b);
		charPair p_c('c', c);
		// Inserting into the priority queues.
		if (p_a.count > 0) p_q.push(p_a);
		if (p_b.count > 0) p_q.push(p_b);
		if (p_c.count > 0) p_q.push(p_c);
		while (p_q.size() > 0) {
			// Pop from top of priority queue.
			charPair c_p = p_q.top();
			p_q.pop();
			// Check if we can insert the element.
			if (canInsert(out_string, c_p.ch)) {
				// Check character.
				out_string += c_p.ch;
				// Insert back into the queue;
				c_p.count--;
			} else {
				if (p_q.size() < 1) break;
				charPair c_p2 = p_q.top();
				p_q.pop();
				out_string += c_p2.ch;
				c_p2.count--;
				if (c_p2.count > 0) p_q.push(c_p2);
			}
			if (c_p.count > 0) {
				p_q.push(c_p);
			}
		}
		return out_string;
	}
};