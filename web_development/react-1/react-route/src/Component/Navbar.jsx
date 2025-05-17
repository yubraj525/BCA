import React from 'react'

const Navbar = () => {
  return (
   <>
   <div>
    <div className="logo"></div>
    <div className="contents">
        <ol>
            <li>Home</li>
            <li>About</li>
            <li>Services</li>
            <li>Contact us</li>
        </ol>
    </div>
    <div className="sections">
        <button>
            Login
            </button>
            <button>
            Sign-Up
            </button>
            </div>
   </div>
   </>
  )
}

export default Navbar