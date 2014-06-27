<?hh // strict
namespace Senary\Support;

use Countable;
use IteratorAggregate;
use Iterator;
use ArrayIterator;

class Hash<Tk, Tv> implements Countable, IteratorAggregate<Tv>
{

    /**
     * Items in storage
     * @var Map
     */
    protected array<Tk, Tv> $items;


    /**
     * Constructor
     *
     * @param  Map $items
     * @return void
     */
    public function __construct(array<Tk, Tv> $items = [])
    {
        $this->items = $items;
    }


    /**
     * Set item value in collection
     *
     * @param  Tk $key
     * @param  Tv $value
     * @return void
     */
    public function set(Tk $key, Tv $value) :void
    {
        $this->items[$key] = $value;
    }


    /**
     * Alias for set
     *
     * @param  Tk $key
     * @param  Tv $value
     * @return void
     */
    public function add(Tk $key, Tv $value) :void
    {
        $this->set($key, $value);
    }


    /**
     * Get item from collection
     *
     * @param  Tk $key
     * @return Tv|null
     */
    public function get(Tk $key) :?Tv
    {
        return $this->exists($key) ? $this->items[$key] : null;
    }


    /**
     * Get all items
     *
     * @return array
     */
    public function all() :array<Tk, Tv>
    {
        return $this->items;
    }


    /**
     * Get first item
     *
     * @return Tv|null
     */
    public function first() :?Tv
    {
        $items = array_values($this->items);
        return array_shift($items);
    }


    /**
     * Get last item
     *
     * @return Tv|null
     */
    public function last() :?Tv
    {
        $items = array_values($this->items);
        return array_pop($items);
    }



    /**
     * Determine if key exists
     *
     * @param  Tk $key
     * @return bool
     */
    public function exists(Tk $key) :bool
    {
        return array_key_exists($key, $this->items);
    }


    /**
     * Merge another array in
     *
     * @param  array $merge
     * @return void
     */
    public function merge(array<Tk, Tv> $merge) :void
    {
        $this->items = array_merge($this->items, $merge);
    }


    /**
     * Alias for exists
     *
     * @param  Tk $key
     * @return bool
     */
    public function has(Tk $key) :bool
    {
        return $this->exists($key);
    }


    /**
     * Get count of items
     *
     * @return int
     */
    public function count() :int
    {
        return count($this->items);
    }


    /**
     * Loop through each item
     *
     * @param  \Closure $callback
     * @return array
     */
    public function each(\Closure $callback) :array<Tk, Tv>
    {
        return array_map($callback, $this->items);
    }


    /**
     * Filter through items
     *
     * @param  \Closure $callback
     * @return array
     */
    public function filter(\Closure $callback) :array<Tk, Tv>
    {
        return array_filter($this->items, $callback);
    }


    /**
     * Get iterator
     *
     * @return Iterator
     */
    public function getIterator() :Iterator<Tv>
    {
        return new ArrayIterator($this->items);
    }


    /**
     * Convert into an array
     *
     * @return array
     */
    public function toArray() :array<Tk, Tv>
    {
        return $this->all();
    }


}
