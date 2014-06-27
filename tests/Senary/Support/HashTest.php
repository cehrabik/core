<?hh

use Senary\Support\Hash;

class HashTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->hash = new Hash();
    }


    /**
     * @test
     */
    public function get_and_set_item()
    {
        $this->hash->set('one', 'bar');
        $this->assertSame('bar', $this->hash->get('one'));

        $this->hash->add('two', 'foo'); // alias
        $this->assertSame('foo', $this->hash->get('two'));

        $this->assertNull( $this->hash->get('zzz') );
    }


    /**
     * @test
     */
    public function get_all_items()
    {
        $this->hash->add('one', 'foo');
        $this->hash->add('two', 'bar');

        $expect = ['one' => 'foo', 'two' => 'bar'];
        $this->assertSame($expect, $this->hash->all());
    }


    /**
     * @test
     */
    public function get_first_item()
    {
        $this->hash->add('one', 'foo');
        $this->hash->add('two', 'bar');

        $this->assertSame('foo', $this->hash->first());
    }


    /**
     * @test
     */
    public function get_last_item()
    {
        $this->hash->add('one', 'foo');
        $this->hash->add('two', 'bar');

        $this->assertSame('bar', $this->hash->last());
    }


    /**
     * @test
     */
    public function determine_if_key_exists()
    {
        $this->assertFalse( $this->hash->exists('foo') );

        $this->hash->set('foo', 'bar');
        $this->assertTrue( $this->hash->exists('foo') );
        $this->assertTrue( $this->hash->has('foo') ); // alias
    }


    /**
     * @test
     */
    public function merge_with_another_array()
    {
        $this->hash->add('one', 'foo');
        $this->hash->add('two', 'bar');
        $others = ['three' => 'hello', 'four' => 'world'];

        $this->hash->merge($others);
        $expect = [
            'one' => 'foo',
            'two' => 'bar',
            'three' => 'hello',
            'four' => 'world',
        ];

        $this->assertSame($expect, $this->hash->all());
    }


    /**
     * @test
     */
    public function count_of_items()
    {
        $this->hash->set('one', 'foo');
        $this->hash->set('two', 'bar');

        $this->assertSame(2, $this->hash->count());
    }


    /**
     * @test
     */
    public function loop_through_each_item()
    {
        $items = [1,2,3];
        $this->hash->merge($items);

        $iteration = 0;
        $mapped = $this->hash->each(function($value) use (&$iteration) {
            $iteration++;

            $this->assertSame($iteration, $value);
            return $value+1;
        });

        $this->assertSame([0 => 2, 1 => 3, 2 => 4], $mapped);
    }


    /**
     * @test
     */
    public function filter_through_items()
    {
        $items = [1,2,3];
        $this->hash->merge($items);

        $iteration = 0;
        $items = $this->hash->filter(function($value) use (&$iteration) {
            $iteration++;

            $this->assertSame($iteration, $value);
            return $value !== 2;
        });

        $this->assertSame([0 => 1, 2 => 3], $items);
    }


    /**
     * @test
     */
    public function get_iterator()
    {
        $iterator = $this->hash->getIterator();
        $this->assertInstanceOf('Iterator', $iterator);
    }


    /**
     * @test
     */
    public function converts_into_array()
    {
        $this->assertSame([], $this->hash->toArray());
    }

}
