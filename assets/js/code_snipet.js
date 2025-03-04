document.addEventListener('DOMContentLoaded', function() {
    // Find all pre elements that should be foldable
    const codeBlocks = document.querySelectorAll('pre');
    
    codeBlocks.forEach(block => {
        // Wrap the pre block in a container
        const container = document.createElement('div');
        container.classList.add('code-block-container');
        block.parentNode.insertBefore(container, block);
        
        // Create header
        const header = document.createElement('div');
        header.classList.add('code-block-header');
        
        // Create first line display
        const firstLine = block.textContent.split('\n')[0];
        const lineDisplay = document.createElement('span');
        lineDisplay.textContent = firstLine;
        
        // Create toggle icon
        const toggleIcon = document.createElement('div');
        toggleIcon.classList.add('toggle-icon');
        
        header.appendChild(lineDisplay);
        header.appendChild(toggleIcon);
        
        // Wrap pre block
        container.appendChild(header);
        container.appendChild(block);
        
        // Add click event to header
        header.addEventListener('click', () => {
            block.classList.toggle('collapsed');
            container.classList.toggle('collapsed');
        });
    });
});