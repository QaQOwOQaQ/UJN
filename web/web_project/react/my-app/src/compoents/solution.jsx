import React, { Component } from 'react';

class Solution extends Component {
    state = { 
        solutions: [
            {number: 100, title: "加工零件", views: 2937},
            {number: 101, title: "二分图", views: 3541},
            {number: 102, title: "网络流", views: 225},
            {number: 103, title: "最近公共祖先", views: 4556},
            {number: 104, title: "背包问题", views: 10045},
            {number: 105, title: "最短路径", views: 45},
            {number: 106, title: "打家劫舍", views: 445},
        ],
    } 

    handleDelete = (item) => {
        const new_solutions = this.state.solutions.filter(solution => solution !== item);
        this.setState({
            solutions: new_solutions,
        });
    }

    render() { 
        if(this.state.solutions.length === 0) {
            return <p className="font-monospace">This is in monospace</p>;
        }
        return (
            <table className="table">
                <thead>
                    <tr className='table-primary'>
                        <th>#</th>
                        <th>Number</th>
                        <th>Title</th>
                        <th>Views</th>
                    </tr>
                </thead>    
                <tbody>
                    {
                        this.state.solutions.map(item => (
                            <tr className='table-info' key={item.number}>
                                <th>{item.number}</th>
                                <th>{item.title}</th>
                                <th>{item.views}</th>
                                <th><button onClick={()=>this.handleDelete(item)} className='btn btn-danger'>delete</button></th>
                            </tr>
                        ))}
                </tbody>
            </table>
        )
    }
}
 
export default Solution;