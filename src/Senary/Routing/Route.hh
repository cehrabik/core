<?hh // strict
namespace Senary\Routing;

class Route
{

    /**
     * Method route response to
     * @var string
     */
    protected string $method;


    /**
     * URI patter for route
     * @var string
     */
    protected string $uri;


    /**
     * Constructor
     *
     * @param  string $route
     * @param  string $uri
     * @return void
     */
    public function __construct(string $method, string $uri) :void
    {
        $this->method = $method;
        $this->uri = $uri;
    }


    /**
     * Get method
     *
     * @return string
     */
    public function getMethod() :string
    {
        return $this->method;
    }


    /**
     * Set method
     *
     * @param  string $method
     * @return self
     */
    public function setMethod(string $method) :this
    {
        $this->method = $method;
        return $this;
    }


    /**
     * Get and set method alias
     *
     * @param  string $method
     * @return self|string
     */
    public function method(?string $method = null) :mixed
    {
        if( is_null($method) ) return $this->method;

        return $this->setMethod($method);
    }


    /**
     * Get uri
     *
     * @return string
     */
    public function getUri() :string
    {
        return $this->uri;
    }


    /**
     * Set uri
     *
     * @param  string $uri
     * @return self
     */
    public function setUri(string $uri) :this
    {
        $this->uri = $uri;
        return $this;
    }


    /**
     * Get and set uri alias
     *
     * @param  string $uri
     * @return self|string
     */
    public function uri(?string $uri = null) :mixed
    {
        if( is_null($uri) ) return $this->uri;

        return $this->setUri($uri);
    }


}
