<?hh // strict
namespace Senary\Support;

use Countable;
use IteratorAggregate;
use ArrayIterator;

trait Collectable<Tk, Tv> implements Countable, IteratorAggregate<Tv>
{

    /**
     * Abstract actual "getting" and "setting" item
     * values to the implementation using the trait.
     */
    protected abstract function getItem(Tk $key) :Tv;
    protected abstract function setItem(Tk $key, Tv $value) :void;
    public abstract function all() :array<Tk, Tv>;


    /**
     * Get item from collection
     *
     * @param  Tk $key
     * @return Tv|null
     */
    public function get(Tk $key) :?Tv
    {
        return $this->exists($key) ? $this->getItem($key) : null;
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
        $this->setItem($key, $value);
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
     * Get first item
     *
     * @return Tv|null
     */
    public function first() :?Tv
    {
        $items = array_values( $this->all() );
        return array_shift($items);
    }


    /**
     * Get last item
     *
     * @return Tv|null
     */
    public function last() :?Tv
    {
        $items = array_values( $this->all() );
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
        return array_key_exists($key, $this->all());
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
        return count($this->all());
    }


    /**
     * Loop through each item
     *
     * @param  \Closure $callback
     * @return array
     */
    public function each(\Closure $callback) :array<Tk, Tv>
    {
        return array_map($callback, $this->all());
    }


    /**
     * Filter through items
     *
     * @param  \Closure $callback
     * @return array
     */
    public function filter(\Closure $callback) :array<Tk, Tv>
    {
        return array_filter($this->all(), $callback);
    }


    /**
     * Get iterator
     *
     * @return Iterator
     */
    public function getIterator() :Iterator<Tv>
    {
        return new ArrayIterator($this->all());
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
