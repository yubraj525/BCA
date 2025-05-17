import React from 'react'
import Nav from './Nav'




const First = () => {
  return (
    <>
<Nav></Nav>
   <div className="product-card">
      {/* Product Image */}
      <div className="product-image">
        <img
          src="https://via.placeholder.com/300x200" // Replace with your product image
          alt="Product"
        />
      </div>

      {/* Product Info */}
      <div className="product-info">
        <h2 className="product-title">Product Name</h2>
        <p className="product-price">$49.99</p>
        <p className="product-description">
          This is a great product with amazing features. Perfect for your needs!
        </p>
        <button className="buy-now">Buy Now</button>
      </div>
    </div>
    </>
  )
}

export default First