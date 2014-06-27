<?hh

use Senary\Http\Response;

class ResponseTest extends TestCase
{

    /**
     * Setup
     */
    public function setUp()
    {
        parent::setUp();
        $this->response = new Response('Some content');
    }


    /**
     * @test
     */
    public function get_and_set_content()
    {
        $this->assertSame('Some content', $this->response->getContent());

        $this->response->setContent('Foo');
        $this->assertSame('Foo', $this->response->getContent());
    }


    /**
     * @test
     */
    public function get_and_set_content_alias()
    {
        $this->assertSame('Some content', $this->response->content());

        $this->response->content('Changed');
        $this->assertSame('Changed', $this->response->getContent());
    }


    /**
     * @test
     */
    public function get_and_set_status()
    {
        $this->assertSame(200, $this->response->getStatus());

        $this->response->setStatus(404);
        $this->assertSame(404, $this->response->getStatus());
    }


    /**
     * @test
     */
    public function get_and_set_status_alias()
    {
        $this->assertSame(200, $this->response->status());

        $this->response->status(302);
        $this->assertSame(302, $this->response->status());
    }


    /**
     * @test
     */
    public function get_and_set_headers()
    {
        $this->assertSame([], $this->response->getHeaders());

        $this->response->setHeaders(['foo' => 'bar']);
        $this->assertSame(['foo' => 'bar'], $this->response->getHeaders());
    }


    /**
     * @test
     */
    public function get_and_set_headers_alias()
    {
        $this->assertSame([], $this->response->headers());

        $this->response->headers(['client' => 'senary']);
        $this->assertSame(['client' => 'senary'], $this->response->getHeaders());
    }


}
