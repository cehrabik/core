<?hh
namespace Senary\Support;

use IteratorAggregate;
use Countable;
use ArrayIterator;

class Listing<Tv> implements IteratorAggregate<Tv>, Countable
{

    /**
     * Items in storage
     * @var array
     */
    protected array<Tv> $items;

    /**
     * Constructor
     *
     * @param  array $items
     * @return void
     */
    public function __construct(array<Tv> $items = []) :void
    {
        $this->items = $items;
    }


    /**
     * Set the value of item at key
     *
     * @param  int $key
     * @param  Tv  $value
     * @return void
     */
    public function set(int $key, Tv $value)
    {
        $this->items[$key] = $value;
    }


    /**
     * Get value of item at key
     *
     * @param  int $key
     * @return Tv|null
     */
    public function get(int $key) :?Tv
    {
        return $this->exists($key) ? $this->items[$key] : null;
    }


    /**
     * Get all items in collection
     *
     * @return array
     */
    public function all() :array<Tv>
    {
        return $this->items;
    }


    /**
     * Push item into storage
     *
     * @param  Tv $value
     * @return void
     */
    public function push(Tv $value) :void
    {
        $this->items[] = $value;
    }


    /**
     * Check if item exists at key
     *
     * @param int $key
     * @return bool
     */
    public function exists(int $key) :bool
    {
        return array_key_exists($key, $this->items);
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
     * Alias for exists
     *
     * @param  int $key
     * @return bool
     */
    public function has(int $key) :bool
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
     * Loop over each item
     *
     * @param  \Closure $callback
     * @return array
     */
    public function each(\Closure $callback) :array<Tv>
    {
        return array_map($callback, $this->items);
    }


    /**
     * Filter through items
     *
     * @param  \Closure $callback
     * @return array
     */
    public function filter(\Closure $callback) :array<Tv>
    {
        return array_filter($this->items, $callback);
    }


    /**
     * Merge arrays
     *
     * @param  array $merge
     * @return void
     */
    public function merge(array<Tv> $merge) :void
    {
        $this->items = array_merge($this->items, $merge);
    }


    /**
     * Get iterator
     *
     * @return ArrayIterator
     */
    public function getIterator() :Iterator<Tv>
    {
        return new ArrayIterator($this->items);
    }


    /**
     * Convert to array
     *
     * @return array
     */
    public function toArray() :array<Tv>
    {
        return $this->all();
    }

}
