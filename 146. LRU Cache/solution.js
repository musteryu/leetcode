/**
 * @constructor
 */

var Node = function(key, val) {
    this.key = key;
    this.val = val;
    this.next = null;
    this.last = null;
};

var LRUCache = function(capacity) {
    this.head = this.tail = new Node(-1);
    this.head.next = null;
    this.size = 0;
    this.capacity = capacity;
    this.map = {};
};

/**
 * @param {Node} node
 * @returns {void}
 */
LRUCache.prototype.popUp = function(node) {
    if (node !== this.tail && node !== this.head) {
        node.last.next = node.next;
        node.next.last = node.last;
        this.tail.next = node;
        node.last = this.tail;
        node.next = null;
        this.tail = node;
    }
}

LRUCache.prototype.del = function(node) {
    if (node !== this.tail) {
        node.last.next = node.next;
        node.next.last = node.last;
        node.last = node.next = null;
    } else {
        node.last = node.next;
    }
    delete this.map[node.key];
    this.size --;
}

/**
 * @param {number} key
 * @returns {number}
 */
LRUCache.prototype.get = function(key) {
    if (this.map[key] !== undefined) {
        var node = this.map[key];
        this.popUp(node);
        return node.val;
    } else return -1;
};

/**
 * @param {number} key
 * @param {number} value
 * @returns {void}
 */
LRUCache.prototype.set = function(key, value) {
    if (this.map[key] !== undefined) {
        this.map[key].val = value;
        this.popUp(this.map[key]);
        return;
    }
    if (this.size >= this.capacity) {
        this.del(this.head.next);
    }
    var node = new Node(key, value);
    this.map[key] = node;
    this.tail.next = node;
    node.last = this.tail;
    this.tail = node;
    node.next = null;
    this.size ++;
};




/**
 * Using Map to implement LRUCache
 */
class LRUCache {
    constructor(capacity) {
        this.capacity = capacity;
        this.map = new Map();
    }
    get(key) {
        if (map.has(key)) {
            var val = map.get(key);
            map.delete(key);
            map.set(key, val);
            return val;
        } else return -1;
    }
    set(key, val) {
        if (map.has(key)) {
            map.delete(key);
            map.set(key, val);
        }
    }
}
