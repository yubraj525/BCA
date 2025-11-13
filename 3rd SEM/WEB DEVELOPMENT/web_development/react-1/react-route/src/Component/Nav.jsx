import React from 'react'

const Nav = () => {
  return (
  <>
   <nav className="navbar">
      {/* Logo Section */}
      <div className="logo">
        <a href="#">MyLogo</a>
      </div>

      {/* Search Bar */}
      <div className="search-bar">
        <input type="text" placeholder="Search..." />
        <button className="search-btn">
          <i className="search-icon">&#128269;</i> {/* Search icon */}
        </button>
      </div>

      {/* Navigation Links */}
      <div className="nav-links">
        <a href="#">Home</a>
        <a href="#">About</a>
        <a href="#">Contact</a>
      </div>
    </nav></>
  )
}

export default Nav