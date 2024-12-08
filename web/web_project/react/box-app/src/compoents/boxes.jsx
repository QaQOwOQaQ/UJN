import React, { Component } from 'react';
import Box from './box.jsx'

class Boxes extends Component {
    // 可以把state理解为一个私有变量
    state = {  
        boxes: [
            {id: 1, x: 1},
            {id: 2, x: 2},
            {id: 3, x: 3},
            {id: 4, x: 4},
        ]
    } 

    handleDelete = (boxId) => {
        const boxes = this.state.boxes.filter(
            box => box.id !== boxId
        );
        this.setState({
            boxes   // 语法糖  
        })
    }

    handleClickLeft = () => {
        this.setState({
            x: this.state.x - 3,
        });
    }

    handleClickRight = () => {
        this.setState({
            x: this.state.x + 3,
        });
    }
    
    
    render() { 
        return (
            <React.Fragment>
                <button type="button" className="btn btn-warning  m-3">Reset</button>
                {this.state.boxes.map(box => (
                    <Box 
                        key = {box.id} 
                        id = {box.id}
                        x = {box.x}
                        onDelete = {this.handleDelete}
                    >
                        {/* 不会显示??why? */}
                        <h1>Hello,World!</h1>
                        <p>Fuck,you!</p>
                    </Box>
                ))}
            </React.Fragment>
        );
    }
}
 
export default Boxes;