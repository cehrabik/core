<?hh
namespace Senary\Support;

class Listing<Tv>
{

    /**
     * Collectable trait
     *
     * @implements \Countable, \IteratorAggregate
     */
    use Collectable<int, Tv>;


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
     * Get item
     *
     * @param  Tk $key
     * @return Tv
     */
    protected function getItem(int $key) :Tv
    {
        return $this->items[$key];
    }


    /**
     * Set item value
     *
     * @param  Tk $key
     * @param  Tv $value
     * @retrn void
     */
    protected function setItem(int $key, Tv $value) :void
    {
        $this->items[$key] = $value;
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
     * Merge arrays
     *
     * @param  array $merge
     * @return void
     */
    public function merge(array<Tv> $merge) :void
    {
        $this->items = array_merge($this->items, $merge);
    }

}
