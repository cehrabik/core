<?hh

use Senary\Support\Listing;

class ListingTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->listing = new Listing();
    }


    /**
     * @test
     */
    public function get_and_set_values_of_items()
    {
        $this->listing->set(3, 'foo');
        $this->assertSame('foo', $this->listing->get(3));
    }


    /**
     * @test
     */
    public function determine_if_item_exists()
    {
        $this->assertFalse($this->listing->exists(99));

        $this->listing->set(1, 'foo');
        $this->assertTrue($this->listing->exists(1));
        $this->assertTrue($this->listing->has(1)); // alias
    }


    /**
     * @test
     */
    public function push_item_onto_collection()
    {
        $this->listing->push('foo');
        $this->assertSame('foo', $this->listing->get(0));
    }


    /**
     * @test
     */
    public function get_all_items_in_collection()
    {
        $this->listing->push('foo');
        $this->listing->push('bar');

        $this->assertSame(['foo', 'bar'], $this->listing->all());
    }


    /**
     * @test
     */
    public function get_first_item()
    {
        $this->listing->push('foo');
        $this->listing->push('bar');

        $this->assertSame('foo', $this->listing->first());
    }


    /**
     * @test
     */
    public function get_last_item()
    {
        $this->listing->push('foo');
        $this->listing->push('bar');

        $this->assertSame('bar', $this->listing->last());
    }


    /**
     * @test
     */
    public function loop_over_each_item()
    {
        $this->listing->push('foo');
        $this->listing->push('bar');

        $new_items = $this->listing->each(function($value) {
            return $value . "s";
        });

        $expect = ['foos', 'bars'];
        $this->assertSame($expect, $new_items);
    }


    /**
     * @test
     */
    public function filter_listing()
    {
        $this->listing->push('foo');
        $this->listing->push('bar');

        $new_items = $this->listing->filter(function($value) {
            return $value !== 'bar';
        });

        $this->assertSame(['foo'], $new_items);
    }


    /**
     * @test
     */
    public function merge_arrays()
    {
        $this->listing->push('foo');
        $this->listing->push('bar');

        $others = ['hello', 'world'];
        $this->listing->merge($others);

        $expect = ['foo', 'bar', 'hello', 'world'];

        $this->assertSame($expect, $this->listing->all());
    }


    /**
     * @test
     */
    public function convert_to_array()
    {
        $this->assertSame([], $this->listing->toArray());
    }

}
