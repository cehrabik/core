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
     * URI pattern for route
     * @var string
     */
    protected string $uri;


    /**
     * Callable action
     * @var \Closure
     */
    protected ?(function() :string) $callback;


    /**
     * To class name
     * @var string
     */
    protected ?string $toClass;


    /**
     * At class method name
     * @var string
     */
    protected ?string $atMethod;


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


    /**
     * Set callable action for route
     *
     * @param  \Closure $callback
     * @return self
     * @throws \InvalidArgumentException
     */
    public function setCallback( (function() :string) $callback) :this
    {
        if( !is_callable($callback) ) throw new \InvalidArgumentException('Argument must be callable');
        $this->callback = $callback;

        return $this;
    }


    /**
     * Alias for setCallback
     *
     * @param  \Closure $callback
     * @return self
     * @throws \InvalidArgumentException
     */
    public function call( (function() :string) $callback) :this
    {
        return $this->setCallback($callback);
    }


    /**
     * Determine if route has callback
     *
     * @return bool
     */
    public function hasCallback() :bool
    {
        return !is_null($this->callback);
    }


    /**
     * Get callback
     *
     * @return string
     */
    public function getCallback() :?(function() :string)
    {
        return $this->callback;
    }


    /**
     * Set class name to use
     *
     * @param  string $toClass
     * @return self
     */
    public function setToClass(string $toClass) :this
    {
        $this->toClass = $toClass;
        return $this;
    }


    /**
     * Alias for set toClass
     *
     * @param  string $toClass
     * @return self
     */
    public function to(string $toClass) :this
    {
        return $this->setToClass($toClass);
    }


    /**
     * Set method to use on class
     *
     * @param  string $atMethod
     * @return self
     */
    public function setAtMethod(string $atMethod) :this
    {
        $this->atMethod = $atMethod;
        return $this;
    }


    /**
     * Alias for set atMethod
     *
     * @param  string $atMethod
     * @return self
     */
    public function at(string $atMethod) :this
    {
        return $this->setAtMethod($atMethod);
    }

}
