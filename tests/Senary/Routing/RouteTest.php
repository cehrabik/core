<?hh

use Senary\Routing\Route;

class RouteTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->route = new Route('GET', '/foo');
    }


    /**
     * @test
     */
    public function gets_and_sets_method()
    {
        $this->assertSame('GET', $this->route->getMethod());

        $this->route->setMethod('POST');
        $this->assertSame('POST' ,$this->route->getMethod());
    }


    /**
     * @test
     */
    public function get_and_set_method_alias()
    {
        $this->assertSame('GET', $this->route->method());

        $this->route->method('POST');
        $this->assertSame('POST' ,$this->route->getMethod());
    }


    /**
     * @test
     */
    public function get_and_set_uri()
    {
        $this->assertSame('/foo', $this->route->getUri());

        $this->route->setUri('/bar');
        $this->assertSame('/bar', $this->route->getUri());
    }


    /**
     * @test
     */
    public function get_and_set_uri_alias()
    {
        $this->assertSame('/foo', $this->route->uri());

        $this->route->uri('/bar');
        $this->assertSame('/bar', $this->route->getUri());
    }


    /**
     * @test
     */
    public function set_callback_action()
    {
        $this->route->call(function() { return 'foo'; });
    }


    /**
     * @test
     *
     * @expectedException \InvalidArgumentException
     */
    public function throws_an_exception_if_callback_isnt_callable()
    {
        $this->route->call('foo');
    }


    /**
     * @test
     */
    public function determines_if_callback_is_set()
    {
        $this->assertFalse( $this->route->hasCallback() );

        $this->route->call(function() { return 'foo'; });
        $this->assertTrue( $this->route->hasCallback() );
    }


    /**
     * @test
     */
    public function gets_callback_result()
    {
        $this->route->call(function() { return 'foo'; });
        $this->assertInstanceOf('Closure', $this->route->getCallback());

        $result = call_user_func($this->route->getCallback());
        $this->assertSame('foo', $result);
    }


    /**
     * @test
     */
    public function sets_class_name_to_use()
    {
        $this->route->to('Senary\Http\Response');
    }


    /**
     * @test
     */
    public function sets_method_name_to_use_on_class()
    {
        $this->route->at('method');
    }


}
