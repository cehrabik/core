<?hh // strict
namespace Senary\Support;

class Hash<Tk, Tv>
{

    /**
     * Collectable trait
     *
     * @implements \Countable, \IteratorAggregate
     */
    use Collectable<Tk, Tv>;


    /**
     * Items in storage
     * @var array
     */
    protected array<Tk, Tv> $items;


    /**
     * Constructor
     *
     * @param  array $items
     * @return void
     */
    public function __construct(array<Tk, Tv> $items = [])
    {
        $this->items = $items;
    }


    /**
     * Get item
     *
     * @param  Tk $key
     * @return Tv
     */
    protected function getItem(Tk $key) :Tv
    {
        return $this->items[$key];
    }


    /**
     * Set item value
     *
     * @param  Tk $key
     * @param  Tv $value
     * @return void
     */
    protected function setItem(Tk $key, Tv $value) :void
    {
        $this->items[$key] = $value;
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
     * Merge another array in
     *
     * @param  array $merge
     * @return void
     */
    public function merge(array<Tk, Tv> $merge) :void
    {
        $this->items = array_merge($this->items, $merge);
    }


}
