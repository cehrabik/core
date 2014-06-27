<?hh // strict
namespace Senary\Http;

/**
 * This is a port of the Symfony HttpKernelInterface.
 * Provides a unified way for handling http, and middlewares.
 *
 * @see https://github.com/symfony/HttpKernel
 * @see http://stackphp.com
 *
 * Symfony License:
 * Copyright (c) 2004-2014 Fabien Potencier
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is furnished
 * to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

interface HandlerInterface
{

    /**
     * Request types
     */
    const int MASTER_REQUEST = 1;
    const int SUB_REQUEST = 2;


    /**
     * Handle request and issue response
     *
     * @param Request $request
     * @param int     $type - either 1 for master or 2 for sub
     * @param bool    $catch - try and "catch" all exceptions
     *
     * @return Response
     */
    public function handle(Request $request, int $type = self::MASTER_REQUEST, bool $catch = true) :Response;

}
